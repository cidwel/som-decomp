.setcpu "65816"
.segment "CODE"
.org $6D12
map_control_0c6d12:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
