
#include <stdio.h>
#include <stdlib.h>

struct Weather {
    float temperature;
    float humidity;
    float pressure;
};

// Function to calculate average
float calculateAverage(float arr[], int n) {
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum / n;
}

// Function to display alerts
void checkAlerts(float t, float h, float p) {
    if (t > 40)
        printf("Alert: High Temperature!\n");

    if (h > 80)
        printf("Alert: High Humidity!\n");

    if (p < 980)
        printf("Alert: Low Atmospheric Pressure!\n");
}

int main() {
    int n;

    printf("Enter number of hourly readings: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of readings.\n");
        return 1;
    }

    struct Weather *w;
    w = (struct Weather *)malloc(n * sizeof(struct Weather));

    if (w == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    float temp[n], humid[n], press[n];

    for (int i = 0; i < n; i++) {
        printf("\nReading %d\n", i + 1);

        printf("Enter Temperature: ");
        scanf("%f", &w[i].temperature);

        printf("Enter Humidity: ");
        scanf("%f", &w[i].humidity);

        printf("Enter Pressure: ");
        scanf("%f", &w[i].pressure);

        temp[i] = w[i].temperature;
        humid[i] = w[i].humidity;
        press[i] = w[i].pressure;
    }

    printf("\n--- DAILY WEATHER SUMMARY ---\n");

    printf("Average Temperature: %.2f C\n",
           calculateAverage(temp, n));

    printf("Average Humidity: %.2f %%\n",
           calculateAverage(humid, n));

    printf("Average Pressure: %.2f hPa\n",
           calculateAverage(press, n));

    printf("\n--- WEATHER ALERTS ---\n");

    for (int i = 0; i < n; i++) {
        printf("\nReading %d:\n", i + 1);

        checkAlerts(w[i].temperature,
                    w[i].humidity,
                    w[i].pressure);
    }

    free(w);

    printf("\nMemory released successfully.\n");

    return 0;
}
