.setcpu "65816"
.segment "CODE"
.org $1C39
map_control_0f1c39:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
