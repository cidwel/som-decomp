.setcpu "65816"
.segment "CODE"
.org $000D
map_control_0f000d:
    .byte $E7 ; previous-row copy count
