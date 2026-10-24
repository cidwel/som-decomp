.setcpu "65816"
.segment "CODE"
.org $192E
map_control_0d192e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E2 ; previous-row copy count
