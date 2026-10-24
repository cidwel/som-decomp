.setcpu "65816"
.segment "CODE"
.org $ADFD
map_control_0eadfd:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E5 ; previous-row copy count
