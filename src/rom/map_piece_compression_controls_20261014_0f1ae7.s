.setcpu "65816"
.segment "CODE"
.org $1AE7
map_control_0f1ae7:
    .byte $E0 ; previous-row copy escape
    .byte $E0 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
