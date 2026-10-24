.setcpu "65816"
.segment "CODE"
.org $74D0
map_control_0d74d0:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
