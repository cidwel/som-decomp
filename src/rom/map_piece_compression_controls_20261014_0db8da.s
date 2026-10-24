.setcpu "65816"
.segment "CODE"
.org $B8DA
map_control_0db8da:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
