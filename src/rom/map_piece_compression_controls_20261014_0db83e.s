.setcpu "65816"
.segment "CODE"
.org $B83E
map_control_0db83e:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
