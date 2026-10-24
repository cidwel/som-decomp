.setcpu "65816"
.segment "CODE"
.org $72FF
map_control_0d72ff:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
