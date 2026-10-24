.setcpu "65816"
.segment "CODE"
.org $496C
map_control_0d496c:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
