.setcpu "65816"
.segment "CODE"
.org $B3E2
map_control_0db3e2:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
