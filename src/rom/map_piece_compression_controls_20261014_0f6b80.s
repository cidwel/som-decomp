.setcpu "65816"
.segment "CODE"
.org $6B80
map_control_0f6b80:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
