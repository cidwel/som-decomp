.setcpu "65816"
.segment "CODE"
.org $4C5B
map_control_0f4c5b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7C ; distance low bit/count
