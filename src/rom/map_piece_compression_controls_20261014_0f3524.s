.setcpu "65816"
.segment "CODE"
.org $3524
map_control_0f3524:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
