.setcpu "65816"
.segment "CODE"
.org $4CFE
map_control_0c4cfe:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
