.setcpu "65816"
.segment "CODE"
.org $4878
map_control_0f4878:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
