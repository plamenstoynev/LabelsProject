# Label Transformation Framework

This project provides a set of classes and decorators for managing and transforming text labels. It uses design patterns such as the **Decorator**, **Proxy**,**Composite**, and **Strategy** patterns to allow dynamic modification of label behaviors, lazy evaluation, and flexible text transformations. The main functionalities include text formatting, transformation, and advanced features like proxying and rich text formatting.

---

## Features

### Core Classes
- **Label (Abstract Base Class)**:
    - Defines the base interface for labels.
    - Provides methods for retrieving text and manipulating decorators.

- **SimpleLabel**:
    - Represents a basic label with plain text.

- **RichLabel**:
    - Extends `Label` to support features like font, size, and color.

- **ProxyLabel**:
    - Implements the **Proxy Design Pattern**.
    - Acts as a proxy for a label, supporting lazy loading and timeout checks.

- **LabelPrinter**:
    - A utility class for printing labels.

### Decorators
- **LabelDecoratorBase**:
    - Abstract class for decorating labels using the **Decorator Design Pattern**.
    - Supports multiple transformations like capitalization, trimming, and space normalization.

- **Specific Decorators**:
    - `CapatilizeDecorator`: Capitalizes text.
    - `LeftTrimDecorator` and `RightTrimDecorator`: Remove leading or trailing spaces.
    - `NormalizeSpacesDecorator`: Standardizes spacing.
    - `CensorDecorator`: Masks specific words.
    - `ReplaceDecorator`: Replaces substrings in the label text.
    - `DecorateDecorator`: Adds additional decoration to the label.

- **TextTransformationDecorator**:
    - Applies transformations like capitalization and trimming using **Strategy Design Pattern**.
    - Leverages transformation objects to encapsulate transformation logic.

- **RandomTransformationDecorator**:
    - Randomly applies transformations from a provided set.

- **CyclingTransformationsDecorator**:
    - Cycles through a list of transformations sequentially.

### Composite Transformations
- **CompositeTransformation**:
    - Combines multiple transformations into a single operation.
    - Allows sequential application of transformations on text.

---

## Design Patterns Used

1. **Decorator Pattern**:
    - Used to dynamically add behavior to `Label` objects without modifying their structure.
    - Allows flexible composition of transformations.

2. **Proxy Pattern**:
    - Implemented in `ProxyLabel` for lazy evaluation, caching, and deferred execution.
    - Optimizes resource usage and ensures time-sensitive operations are handled properly.

3. **Strategy Pattern**:
    - Enables interchangeable text transformation logic through objects such as `Capitalize`, `Trim`, and `NormalizeSpaces`.
    - Facilitates flexible and reusable transformation implementations.

4 **Composite Pattern**:
    - Used in `CompositeTransformation` to treat single and multiple transformations uniformly.
    - Allows sequential application of multiple transformations on text.
---

## File Overview

| File | Description |
|------|-------------|
| `Label.h` | Base class for labels, providing the core interface. |
| `SimpleLabel.h` | Represents a plain text label. |
| `RichLabel.h` | A label with advanced formatting features like font and color. |
| `ProxyLabel.h` | Proxy implementation for deferred or conditional label behavior. |
| `LabelPrinterer.h` | Utility for printing label content. |
| `LabelDecoratoBase.h` | Base class for all decorators, with predefined decorator implementations. |
| `TextTransformationDecorator.h` | Applies a single transformation to a label. |
| `RandomTransformationDecorator.h` | Randomly selects and applies transformations. |
| `CyclingTransformationsDecorator.h` | Cycles through multiple transformations. |
| `CompositeTransformation.h` | Aggregates and sequentially applies multiple transformations. |

---

