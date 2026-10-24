.setcpu "65816"
.segment "CODE"
.org $1FE6
map_control_0f1fe6:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
