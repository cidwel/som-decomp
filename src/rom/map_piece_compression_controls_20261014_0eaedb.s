.setcpu "65816"
.segment "CODE"
.org $AEDB
map_control_0eaedb:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
