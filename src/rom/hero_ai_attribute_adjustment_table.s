; Three packed two-bit adjustments for AI-controlled hero attributes.
.setcpu "65816"
.segment "CODE"
.org $473F
hero_ai_attribute_adjustment_table:
    .byte $35, $04, $04, $17, $32, $00, $00, $23
    .byte $32, $00, $00, $23, $35, $04, $04, $17
