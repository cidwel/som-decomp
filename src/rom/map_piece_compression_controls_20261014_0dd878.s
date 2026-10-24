.setcpu "65816"
.segment "CODE"
.org $D878
map_control_0dd878:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
