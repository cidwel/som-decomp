.setcpu "65816"
.segment "CODE"
.org $B3C0
map_control_0db3c0:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
