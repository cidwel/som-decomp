.setcpu "65816"
.segment "CODE"
.org $1AD1
map_control_0f1ad1:
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
