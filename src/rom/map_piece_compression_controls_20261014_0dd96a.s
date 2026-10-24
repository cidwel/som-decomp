.setcpu "65816"
.segment "CODE"
.org $D96A
map_control_0dd96a:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
