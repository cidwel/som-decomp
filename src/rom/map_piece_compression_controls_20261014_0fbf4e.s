.setcpu "65816"
.segment "CODE"
.org $BF4E
map_control_0fbf4e:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
