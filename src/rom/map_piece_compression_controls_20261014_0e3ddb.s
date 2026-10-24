.setcpu "65816"
.segment "CODE"
.org $3DDB
map_control_0e3ddb:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
