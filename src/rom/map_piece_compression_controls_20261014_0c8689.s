.setcpu "65816"
.segment "CODE"
.org $8689
map_control_0c8689:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
