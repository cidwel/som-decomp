.setcpu "65816"
.segment "CODE"
.org $E42E
map_control_0fe42e:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
