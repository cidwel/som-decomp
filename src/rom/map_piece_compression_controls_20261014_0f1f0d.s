.setcpu "65816"
.segment "CODE"
.org $1F0D
map_control_0f1f0d:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
