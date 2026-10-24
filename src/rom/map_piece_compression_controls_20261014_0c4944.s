.setcpu "65816"
.segment "CODE"
.org $4944
map_control_0c4944:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
