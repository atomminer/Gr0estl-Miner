    groestl groestl(
           .ap_clk(clk_h),
           .ap_rst(reset_break),
           .ap_start(start_hash),
           .ap_done(),
           .ap_idle(),
           .ap_ready(),
           .data0({ws0[31:0], ws0[63:32]}), // data dword0
           .data1({ws1[31:0], ws1[63:32]}),
           .data2({ws2[31:0], ws2[63:32]}),
           .data3({ws3[31:0], ws3[63:32]}),
           .data4({ws4[31:0], ws4[63:32]}),
           .data5({ws5[31:0], ws5[63:32]}),
           .data6({ws6[31:0], ws6[63:32]}),
           .data7({ws7[31:0], ws7[63:32]}),
           .data8({ws8[31:0], ws8[63:32]}),
           .data9({ws9[31:0], ws9[63:32]}),
           .target7(target7), // dword7 from target
           .target6(target6), // dword6 from target
           .startnonce(32'h00000000),
           .ticket_V_ap_vld(hashFound),
           .result_V(nonce)
   );
