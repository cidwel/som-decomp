.setcpu "65816"
.segment "CODE"
.org $AD17
map_control_0dad17:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
