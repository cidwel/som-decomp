.setcpu "65816"
.segment "CODE"
.org $512A
map_control_0c512a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
