.setcpu "65816"
.segment "CODE"
.org $7978
map_control_0c7978:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
