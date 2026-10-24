.setcpu "65816"
.segment "CODE"
.org $BF3A
map_control_0fbf3a:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
