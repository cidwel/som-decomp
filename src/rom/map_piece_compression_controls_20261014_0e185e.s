.setcpu "65816"
.segment "CODE"
.org $185E
map_control_0e185e:
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
