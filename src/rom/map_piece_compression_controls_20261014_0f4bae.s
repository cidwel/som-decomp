.setcpu "65816"
.segment "CODE"
.org $4BAE
map_control_0f4bae:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
