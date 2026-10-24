.setcpu "65816"
.segment "CODE"
.org $3501
map_control_0c3501:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
