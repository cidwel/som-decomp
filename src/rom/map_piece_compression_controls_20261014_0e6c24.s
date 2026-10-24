.setcpu "65816"
.segment "CODE"
.org $6C24
map_control_0e6c24:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count
