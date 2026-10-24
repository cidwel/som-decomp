.setcpu "65816"
.segment "CODE"
.org $8E49
map_control_0f8e49:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
