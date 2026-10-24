.setcpu "65816"
.segment "CODE"
.org $EC72
map_control_0eec72:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
