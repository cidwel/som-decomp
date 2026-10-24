.setcpu "65816"
.segment "CODE"
.org $BCFD
map_control_0fbcfd:
    .byte $E9 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
