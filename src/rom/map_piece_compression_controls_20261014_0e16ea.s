.setcpu "65816"
.segment "CODE"
.org $16EA
map_control_0e16ea:
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
