.setcpu "65816"
.segment "CODE"
.org $4CAB
map_control_0c4cab:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
