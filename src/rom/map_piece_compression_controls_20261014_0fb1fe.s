.setcpu "65816"
.segment "CODE"
.org $B1FE
map_control_0fb1fe:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
