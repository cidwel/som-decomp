.setcpu "65816"
.segment "CODE"
.org $720A
map_control_0f720a:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
