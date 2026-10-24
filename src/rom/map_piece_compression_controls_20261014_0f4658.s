.setcpu "65816"
.segment "CODE"
.org $4658
map_control_0f4658:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
