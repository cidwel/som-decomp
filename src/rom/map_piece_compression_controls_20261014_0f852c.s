.setcpu "65816"
.segment "CODE"
.org $852C
map_control_0f852c:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E1 ; previous-row copy count
