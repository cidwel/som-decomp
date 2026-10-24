.setcpu "65816"
.segment "CODE"
.org $9838
map_control_0f9838:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
