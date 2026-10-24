.setcpu "65816"
.segment "CODE"
.org $D601
map_control_0ed601:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
