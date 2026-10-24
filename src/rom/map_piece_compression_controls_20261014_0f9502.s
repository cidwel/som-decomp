.setcpu "65816"
.segment "CODE"
.org $9502
map_control_0f9502:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
