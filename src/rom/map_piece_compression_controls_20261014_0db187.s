.setcpu "65816"
.segment "CODE"
.org $B187
map_control_0db187:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
