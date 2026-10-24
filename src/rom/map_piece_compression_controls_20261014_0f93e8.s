.setcpu "65816"
.segment "CODE"
.org $93E8
map_control_0f93e8:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
