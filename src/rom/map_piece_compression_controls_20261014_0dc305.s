.setcpu "65816"
.segment "CODE"
.org $C305
map_control_0dc305:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
