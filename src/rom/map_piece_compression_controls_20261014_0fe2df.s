.setcpu "65816"
.segment "CODE"
.org $E2DF
map_control_0fe2df:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
