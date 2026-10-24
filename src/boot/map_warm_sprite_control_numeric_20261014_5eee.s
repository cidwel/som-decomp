; Reader-bounded numeric metadata from C7B480 decoded resource.
.setcpu "65816"
.segment "RODATA"
.org $5EEE
warm_control_5eee:
    .byte $18, $C8, ($1B | $00) ; x-offset, y, tile-ID | attribute
    .byte $18, $D0, ($1B | $40) ; x-offset, y, tile-ID | attribute
    .byte $20, $C8, ($1B | $80) ; x-offset, y, tile-ID | attribute
    .byte $20, $D0, ($1B | $C0) ; x-offset, y, tile-ID | attribute
    .byte $18, $C8, ($28 | $00) ; x-offset, y, tile-ID | attribute
    .byte $18, $D0, ($29 | $00) ; x-offset, y, tile-ID | attribute
    .byte $20, $C8, ($2A | $00) ; x-offset, y, tile-ID | attribute
    .byte $20, $D0, ($1B | $C0) ; x-offset, y, tile-ID | attribute
    .byte $18, $D0, ($2B | $00) ; x-offset, y, tile-ID | attribute
    .byte $18, $D0, ($2B | $00) ; x-offset, y, tile-ID | attribute
    .byte $20, $C8, ($2C | $00) ; x-offset, y, tile-ID | attribute
    .byte $20, $D0, ($2D | $00) ; x-offset, y, tile-ID | attribute
