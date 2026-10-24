.setcpu "65816"
.segment "CODE"
.org $22BD
map_control_0f22bd:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
